#include "UserFormatter.h"

int UserFormatter::INDENTATION_LENGTH = 100;

string UserFormatter::format(unordered_set<Item, Item::Hasher> items) {
	string itemsFormatted = "News found: ";
	itemsFormatted.append(std::to_string(items.size()) + '\n');
	for (Item item : items) {
		itemsFormatted.append(string(INDENTATION_LENGTH, '-') + '\n');
		itemsFormatted.append("Title: ");
		itemsFormatted.append(normalize(item.getTitle().getTextContent()) + '\n');
		itemsFormatted.append("Description: ");
		itemsFormatted.append(normalize(item.getDescription().getTextContent()) + '\n');
		itemsFormatted.append("Link: ");
		itemsFormatted.append(normalize(item.getLink().getTextContent()) + '\n');
	}
	return itemsFormatted;
}