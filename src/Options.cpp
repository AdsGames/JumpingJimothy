#include "Options.h"

bool Options::music_enabled=true;
bool Options::sfx_enabled=true;

Options::Options()
{
    read_data();

    options_font = al_load_ttf_font( "fonts/munro.ttf", 18, 0);


    OptionsUI.addElement(new UIElement(50, 50, "Pick a choice",options_font));
    OptionsUI.getElementByText("Pick a choice") -> setVisibleBackground(false);
    OptionsUI.getElementByText("Pick a choice") -> setTextColour(al_map_rgb(255,255,255));



    OptionsUI.addElement(new Button(100, 100, "Toggle Music",options_font));
    OptionsUI.addElement(new Button(100, 150, "Toggle SFX",options_font));


}

Options::~Options()
{
  //dtor
}

void Options::draw(){

    al_clear_to_color( al_map_rgb(50,50,50));

    OptionsUI.draw();


}

void Options::update(){

  OptionsUI.update();

}


void Options::read_data(){

    //Doc
  rapidxml::xml_document<> doc;

//   Make an xml object
  std::ifstream theFile("data/options_data.xml");
  std::vector<char> xml_buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
  xml_buffer.push_back('\0');

  // Parse the buffer using the xml file parsing library into doc
  doc.parse<0>(&xml_buffer[0]);

//   Find our root node
  rapidxml::xml_node<> * root_node;
  root_node = doc.first_node("data");

   //Iterate over the nodes
  for (rapidxml::xml_node<> * object_node = root_node -> first_node("value"); object_node; object_node = object_node -> next_sibling()){

    // It's not a hack if you like it
    if(object_node -> first_attribute("sfx")!=nullptr){



      std::string result = object_node -> first_attribute("sfx") -> value();
      if(result=="enabled")
        sfx_enabled=true;
      else
        sfx_enabled=false;
    }

    if(object_node -> first_attribute("music")!=nullptr){
      if(object_node -> first_attribute("music") -> value() == "enabled")
        music_enabled=true;
      else
        music_enabled=false;
    }
  }
}

void Options::write_data(){


  rapidxml::xml_document<> doc;
  rapidxml::xml_node<>* decl = doc.allocate_node(rapidxml::node_declaration);
  decl -> append_attribute( doc.allocate_attribute("version", "1.0"));
  decl -> append_attribute( doc.allocate_attribute("encoding", "utf-8"));
  doc.append_node(decl);

  rapidxml::xml_node<>* root_node = doc.allocate_node( rapidxml::node_element, "data");
  doc.append_node(root_node);

  // Tile

    char *node_name = doc.allocate_string("value");
    rapidxml::xml_node<>* object_node = doc.allocate_node( rapidxml::node_element, node_name);



    object_node -> append_attribute( doc.allocate_attribute("sfx", doc.allocate_string("enabled")));
    root_node -> append_node( object_node);





    //char *newStatusChar = doc.allocate_string(newStatus.c_str());






  // Save to file
  std::ofstream file_stored("data/options_data.xml");
  file_stored << doc;
  file_stored.close();
  doc.clear();




}






























