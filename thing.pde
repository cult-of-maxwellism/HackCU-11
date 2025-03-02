import controlP5.*;
import java.io.*;

ControlP5 cp5;
Textfield inputField;
Button sendButton;
Button startButton;
StringBuilder output = new StringBuilder(); // Use StringBuilder for efficiency
Process process;
BufferedWriter processWriter;
Thread outputReaderThread;
boolean processRunning = false;

void setup() {
  size(700, 500);
  cp5 = new ControlP5(this);

  // Start ./a.out
  startButton = cp5.addButton("Start ./a.out")
                   .setPosition(50, 50)
                   .setSize(150, 30);

  // Input field for user to send data to ./a.out
  inputField = cp5.addTextfield("Input")
                  .setPosition(50, 100)
                  .setSize(400, 30)
                  .setAutoClear(true);

  sendButton = cp5.addButton("Send")
                  .setPosition(470, 100)
                  .setSize(80, 30);
}

void draw() {
  background(50);
  fill(255);
  text(output.toString(), 50, 150, 600, 300);  // Display real-time output
}

void Start_a_out() {
  if (!processRunning) {
    startProcess();
  } else {
    output.append("Process is already running!\n");
  }
}

void Send() {
  if (processWriter != null) {
    sendInput(inputField.getText());
  }
}

void startProcess() {
  try {
    ProcessBuilder pb = new ProcessBuilder("~/Documents/HackCu-11/HackCU-11/a.out");
    pb.redirectErrorStream(true); // Merge stdout and stderr
    process = pb.start();
    processRunning = true;

    // Setup writer for sending input
    processWriter = new BufferedWriter(new OutputStreamWriter(process.getOutputStream()));

    // Start a thread to continuously read output
    outputReaderThread = new Thread(() -> {
      try {
        BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
        String line;
        while ((line = reader.readLine()) != null) {
          output.append(line).append("\n");
          println(line); // Debugging in Processing console
        }
        processRunning = false; // Mark process as stopped when it ends
      } catch (IOException e) {
        output.append("Error reading output: ").append(e.getMessage()).append("\n");
      }
    });

    outputReaderThread.start();

  } catch (IOException e) {
    output.append("Error starting process: ").append(e.getMessage()).append("\n");
  }
}

void sendInput(String userInput) {
  try {
    processWriter.write(userInput + "\n"); // Send input with newline
    processWriter.flush();
    println("Sent: " + userInput);
  } catch (IOException e) {
    output.append("Error sending input: ").append(e.getMessage()).append("\n");
  }
}
