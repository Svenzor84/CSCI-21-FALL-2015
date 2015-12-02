/*
 * Programming Challenge 28 MagicItem Implementation
 *
 * Steve Ross-Byers
 * Date created: 12/1/2015
 * Last date modified: 12/1/2015
 */
 
 #include "MagicItem.h"
 
 MagicItem::MagicItem(string newName, unsigned int newValue, string newDescription, unsigned int newManaRequired)
 : Item(newName, newValue), description(newDescription), manaRequired(newManaRequired)
 {}
 
 MagicItem::~MagicItem() {
     
 }
 
 void MagicItem::setDescription(string newDescription) {
     description = newDescription;
 }
 
 void MagicItem::setManaRequired(unsigned int newManaRequired) {
  manaRequired = newManaRequired;
     
 }
 
 string MagicItem::getDescription() {
     return description;
 }
 
 unsigned int MagicItem::getManaRequired() {
     return manaRequired;
 }
 
 string MagicItem::toString() {
     stringstream ss;
     ss << Item::toString() << ", " << description << ", requires " << manaRequired << " mana";
     return ss.str();
 }