/*
 * PostListController.cpp
 *
 *  Created on: Jul 14, 2016
 *      Author: Gilang
 */

#include "Controller/PostListController.h"

Heliosky::Controller::PostListController::PostListController(
		TFC::Framework::ControllerManager* m) :
	TFC::Framework::ControllerBase(m, &postListView, CONTROLLER_POSTLIST) // Calling the parent class constructor
{
	// Assign adapter to PostListView
	postListView.PostListDataSource = &this->postListAdapter;
}


void Heliosky::Controller::PostListController::OnLoad(TFC::ObjectClass* param)
{
	dlog_print(DLOG_DEBUG, LOG_TAG, "Preparing async operation");

	// Prepare web service call
	std::shared_ptr<WebService::PostWebService> postWsInstance(new WebService::PostWebService);

	// Load post asynchronously
	tfc_async
	{
		return postWsInstance->Call();
	}
	tfc_async_complete(decltype(postWsInstance->Call())&& result)
	{
		dlog_print(DLOG_DEBUG, LOG_TAG, "Finished async operation");

		if(result.Response == nullptr)
		{
			dlog_print(DLOG_DEBUG, LOG_TAG, "Error during calling web service");
		}
		else
		{
			// Store item to Adapter
			std::vector<Heliosky::Model::Post*>* list = result.Response;

			for(auto item : *list)
			{
				dlog_print(DLOG_DEBUG, LOG_TAG, "Item ID: %d Title: %s", item->postId, item->title.c_str());
				this->postListAdapter.AddItem(item, &View::PostListView::PostListItemClass);
			}

			// Destroy the vector as it is not used anymore
			delete list;
		}
	};
}

void Heliosky::Controller::PostListController::OnListItemClicked(TFC::Components::GenericList* src,
	void*)
{
}
