#include "Title.h"
#include <algorithm>

char Title::KEYWORD_SEPARATOR = ' ';

Title::Title() : TextNode::TextNode("") {
}

Title::Title(xml_node node) : TextNode::TextNode(node.child_value()) {
	string keyword = "";
	for (int i = 0; i < textContent.length(); i++) {
		if (textContent[i] != KEYWORD_SEPARATOR) {
			keyword += std::toupper(textContent.at(i));
		}
		else {
			keywords.push_back(keyword);
			keyword = "";
		}
	}
	keywords.push_back(keyword);
}

bool Title::includes(string keyword) {
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);
	return std::find(keywords.begin(), keywords.end(), keyword) != keywords.end();
}

bool Title::operator==(const Title& description) const {
	return textContent == description.textContent;
}
