import com.krab.lazy.*;
import processing.pdf.*;

LazyGui gui;

void setup(){
    size(800,800,P2D);
    gui = new LazyGui(this);
}

void draw(){
    background(gui.colorPicker("background").hex);
}
