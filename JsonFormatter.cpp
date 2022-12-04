#include "JsonFormatter.h"
#include <functional>
#include <numeric>

using std::accumulate;

string JsonFormatter::format(unordered_set<Item, Item::Hasher> items) {
	vector<string> itemsRepresentations;
	for (Item item : items) {
		string itemRepresentation = "{\"title\": \"";
		itemRepresentation.append(item.getTitle().getTextContent());
		itemRepresentation.append("\", \"description\": \"");
		itemRepresentation.append(item.getDescription().getTextContent());
		itemRepresentation.append("\", \"link\": \"");
		itemRepresentation.append(item.getLink().getTextContent());
		itemRepresentation.append("\"}");
		itemsRepresentations.push_back(itemRepresentation);
	}
	string itemsFormatted = "[";
	for (int i = 0; i < itemsRepresentations.size() - 1; i++) {
		itemsFormatted.append(itemsRepresentations[i]);
		itemsFormatted.append(", ");
	}
	itemsFormatted.append(itemsRepresentations[itemsRepresentations.size() - 1]);
	itemsFormatted.append("]");
	return itemsFormatted;
}