#include <iostream>
#include <string>
#include "ItemType.h"


ItemType:: ItemType() {
  value = 0; //sets value to 0                                                                                             
}

Comparison ItemType::compareTo(ItemType item) {
  //returns enumeration after comparing vlaue                                                                              
  if (value == item.value) { //equal                                                                                       
    return EQUAL;
  } else if (value < item.value) { //less                                                                                  
    return LESS;
  } else { //greater                                                                                                       
    return GREATER;
  }
}

int ItemType::getValue() const{
  return value; //returns item value                                                                                       
}

void ItemType::initialize(int num) {
  value = num; //sets item value                                                                                           
}




