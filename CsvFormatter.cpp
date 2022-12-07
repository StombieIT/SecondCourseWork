#include "CsvFormatter.h"

string CsvFormatter::format(unordered_set<Item, Item::Hasher> items) {
	string itemsFormatted = "title,description,link\n";
	for (Item item : items) {
		itemsFormatted.append(normalize(item.getTitle().getTextContent()));
		itemsFormatted.append(",");
		itemsFormatted.append(normalize(item.getDescription().getTextContent()));
		itemsFormatted.append(",");
		itemsFormatted.append(normalize(item.getLink().getTextContent()));
		itemsFormatted.append("\n");
	}
	return itemsFormatted;
}