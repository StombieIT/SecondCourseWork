#include "CsvFormatter.h"

string CsvFormatter::FIELD_SEPARATOR = "; ";

string CsvFormatter::format(unordered_set<Item, Item::Hasher> items) {
	string itemsFormatted = "title";
	itemsFormatted.append(FIELD_SEPARATOR);
	itemsFormatted.append("description");
	itemsFormatted.append(FIELD_SEPARATOR);
	itemsFormatted.append("link");
	itemsFormatted.append("\n");
	for (Item item : items) {
		itemsFormatted.append(normalize(item.getTitle().getTextContent()));
		itemsFormatted.append(FIELD_SEPARATOR);
		itemsFormatted.append(normalize(item.getDescription().getTextContent()));
		itemsFormatted.append(FIELD_SEPARATOR);
		itemsFormatted.append(normalize(item.getLink().getTextContent()));
		itemsFormatted.append("\n");
	}
	return itemsFormatted;
}