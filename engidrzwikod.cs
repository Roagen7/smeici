public Program()

{

Runtime.UpdateFrequency = UpdateFrequency.Update10;
}





public void Main(string argument, UpdateType updateSource)

{
  
    
    var panel  = GridTerminalSystem.GetBlockWithName("Text panel") as IMyTextPanel;
    var door = GridTerminalSystem.GetBlockWithName("Door") as IMyDoor;
   
    if(panel.GetPublicText() == "2137"){
    
    door.OpenDoor();

    }
    else{

    door.CloseDoor();

    }
}

