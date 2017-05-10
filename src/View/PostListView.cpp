/*
 * PostListView.cpp
 *
 *  Created on: Jul 14, 2016
 *      Author: Gilang
 */

#include "View/PostListView.h"

Evas_Object* Heliosky::View::PostListView::CreateView(Evas_Object* root)
{
	// Call create method of postList to build the widget
	postList.Create(root);

	// Return the postList object. Framework automagically convert component classes
	// into an Evas_Object pointer
	return postList;
}

Heliosky::View::PostListView::PostListView() :
	PostListDataSource(postList.DataSource), // We have to initialize the reference we declared in the header
	eventListItemClicked(postList.eventItemClicked)
{

}

// Define the static field as singleton
Heliosky::View::PostListView::PostListItemClassDef Heliosky::View::PostListView::PostListItemClass;

Heliosky::View::PostListView::PostListItemClassDef::PostListItemClassDef() :
	SimpleGenericListItemClass("type1")
{
	// Map fields of the model into generic list EDC style
	AddToMap(&Heliosky::Model::Post::title, "elm.text");
	AddToMap(&Heliosky::Model::Post::excerpt, "elm.text.sub");
}

Evas_Object* Heliosky::View::PostListView::PostListItemClassDef::GetContent(
		Model::Post* data, Evas_Object* obj, const char* part) {
	return nullptr;
}
