#include "JsonFormatter.h"
#include <functional>
#include <numeric>

string JsonFormatter::format(unordered_set<Item, Item::Hasher> items) {
	vector<string> itemsRepresentations;
	for (Item item : items) {
		string itemRepresentation = "\t{\n\t\t\"title\": \"";
		itemRepresentation.append(normalize(item.getTitle().getTextContent()));
		itemRepresentation.append("\",\n\t\t\"description\": \"");
		itemRepresentation.append(normalize(item.getDescription().getTextContent()));
		itemRepresentation.append("\",\n\t\t\"link\": \"");
		itemRepresentation.append(normalize(item.getLink().getTextContent()));
		itemRepresentation.append("\"\n\t}");
		itemsRepresentations.push_back(itemRepresentation);
	}
	string itemsFormatted = "[";
	if (itemsRepresentations.empty()) {
		itemsFormatted.append("]");
		return itemsFormatted;
	}
	itemsFormatted.append("\n");
	for (int i = 0; i < itemsRepresentations.size() - 1; i++) {
		itemsFormatted.append(itemsRepresentations[i]);
		itemsFormatted.append(",\n");
	}
	itemsFormatted.append(itemsRepresentations[itemsRepresentations.size() - 1]);
	itemsFormatted.append("\n]");
	return itemsFormatted;
}