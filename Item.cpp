#include "Item.h"

Item::Item(xml_node node) {
	this->title = Title(node.child("title"));
	this->description = Description(node.child("description"));
	this->link = Link(node.child("link"));
}

Title Item::getTitle() const {
	return title;
}

Description Item::getDescription() const {
	return description;
}

Link Item::getLink() const {
	return link;
}

bool Item::operator==(const Item& item) const {
	return title == item.title &&
		description == item.description &&
		link == item.link;
		   
}