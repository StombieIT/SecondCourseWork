#pragma once
#include "TextNode.h"
#include "Title.h"
#include "Description.h"
#include "Link.h"
#include <pugixml.hpp>

using pugi::xml_node;

class Item {
private:
	Title title;
	Description description;
	Link link;
public:
	Item(xml_node node);
	Title getTitle() const;
	Description getDescription() const;
	Link getLink() const;
	bool operator==(const Item& item) const;
	class Hasher
	{
	public:
		size_t operator()(const Item& item) const
		{
			size_t titleHashCode = std::hash<string>()(item.getTitle().getTextContent());
			size_t descriptionHashCode = std::hash<string>()(item.getDescription().getTextContent());
			size_t linkHashCode = std::hash<string>()(item.getLink().getTextContent());
			return titleHashCode ^ descriptionHashCode ^ linkHashCode;
		}
	};
};