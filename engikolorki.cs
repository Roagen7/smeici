public Program() {
          Runtime.UpdateFrequency = UpdateFrequency.Update10; 
        
        }
int count = 0;
Color red = new Color(150,0,0);
Color blue = new Color(0,0,150);


public void Main(){
    var display = GridTerminalSystem.GetBlockWithName("Wide LCD panel") as  IMyTextPanel;
    display.FontColor = red;
    display.FontSize = 5;
    display.WritePublicText("Roksa na węgiel");
    display.ShowPublicTextOnScreen();   
   
    
    if(count >10){
        display.FontColor = blue;
        display.WritePublicText("Askonar diament");
        display.ShowPublicTextOnScreen();
        Echo("Got in");
        if(count > 15){
            count = 0;
          }
    }
    count+=1;
    Echo("one full loop");
}
