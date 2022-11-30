#pragma once
#include "TextNode.h"
#include "Title.h"
#include "Description.h"
#include "Link.h"
#include <pugixml.hpp>

using namespace pugi;

class Item {
private:
	Title title;
	Description description;
	Link link;
public:
	Item(xml_node node);
	Title getTitle() const;
	Description getDescription();
	Link getLink();
};