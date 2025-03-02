import java.io.*;

void setup () {
  size (100, 100);
}

void draw() {
  line (0,0,width,height);
  sendData();
}

void sendData() {
    try {
      Process pb = new ProcessBuilder("/home/archmagosgreel/Documents/HackCu-11/HackCU-11/a.out").start();
      //pb.redirectErrorStream(true);
      //Process proc = pb.start();
      
      OutputStream os = pb.getOutputStream();
      InputStream is = pb.getInputStream();
      BufferedReader reader = new BufferedReader(new InputStreamReader(is));
      PrintWriter writer = new PrintWriter(os);
        
        int num = 2;
        writer.println(num);
        writer.flush();
        
        String line;
        while ((line = reader.readLine()) != null) {
          println("C++ says: " + line);
        }
        
        writer.println(num);
        writer.flush();
        pb.waitFor();
    } catch (Exception e) {
        e.printStackTrace();
    }
}
/*PrintWriter output;

void setup() {
  // Create a new file in the sketch directory
  output = createWriter("positions.txt"); 
}

void draw() {
  point(mouseX, mouseY);
  output.println(mouseX + "\t" + mouseY); // Write the coordinate to the file
}

void keyPressed() {
  output.flush(); // Writes the remaining data to the file
  output.close(); // Finishes the file
  exit(); // Stops the program
}*/
