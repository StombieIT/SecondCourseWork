#pragma once
#include "TextNode.h"

using pugi::xml_node;

class Description : public TextNode
{
public:
	Description();
	Description(xml_node node);
	bool operator==(const Description& description) const;
};

