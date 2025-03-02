void parseFile() {
  String file = "../vehicle-directory/123.txt";
  BufferedReader reader = createReader(file);
  String line = null;
  try {
    while ((line = reader.readLine()) != null) {
      String[] pieces = split(line, TAB);
      int x = int(pieces[0]);
      int y = int(pieces[1]);
      point(x, y);
    }
    reader.close();
  } catch (IOException e) {
    e.printStackTrace();
  }
} 
