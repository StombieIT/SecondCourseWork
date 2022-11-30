#include "Item.h"

Item::Item(xml_node node) {
	this->title = Title(node.child("title"));
	this->description = Description(node.child("description"));
	this->link = Link(node.child("link"));
}

Title Item::getTitle() const {
	return title;
}

Description Item::getDescription() {
	return description;
}

Link Item::getLink() {
	return link;
}