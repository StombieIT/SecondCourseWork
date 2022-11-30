#include "TextNode.h"

TextNode::TextNode(string textContent) {
	this->textContent = textContent;
}

string TextNode::getTextContent() {
	return textContent;
}