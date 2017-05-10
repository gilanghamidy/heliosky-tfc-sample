/*
 * PostListController.h
 *
 *  Created on: Jul 14, 2016
 *      Author: Gilang
 */

#ifndef POSTLISTCONTROLLER_H_
#define POSTLISTCONTROLLER_H_

#include "View/PostListView.h"
#include "WebService/PostWebService.h"
#include "TFC/Async.h"
#include "Model/Post.h"

namespace Heliosky
{
	namespace Controller
	{
		class PostListController : public TFC::Framework::ControllerBase
		{
		private:
			View::PostListView postListView;

			// Declare an Adapter to hold list item
			TFC::Components::Adapter postListAdapter;

		public:
			// Controller must have constructor with this exact parameter
			PostListController(TFC::Framework::ControllerManager* m);

			// This method will be called when the controller is loaded by the application
			virtual void OnLoad(TFC::ObjectClass* param);

			void OnListItemClicked(TFC::Components::GenericList* src, void*);
		};
	}
}



#endif /* POSTLISTCONTROLLER_H_ */
