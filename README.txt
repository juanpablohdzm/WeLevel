This repository contains the tasks given by the company WeLevel for the Unreal Engine Developer position. 

Tasks and requirements are not shared to protect the privacy of the company for this and any further application process. 

Although any of the tasks and requirements are not shared, the code will be generally explained to give the recruiters and understandment of the project.

###TEST###
1.Open the map TestMap
2.Hit play
3.Click F on the keyboard to add a tag to the target

###CODE####

The project consists in two classes. 

WLActor:
	1-This class will serve as the base class for the target actor that contains an FGameplayTagContainer, as needed to insert new tags in the actor
	2-The tag container is made private and encapsulation is implemented to read the content and write to it. 
	3-GetTags returns a reference const of the tag container for comparison
	4-AddTag function is provided to insert a tag inside the tag container. 

WLAsyncTagListener:
	Derived from UBlueprintAsyncActionBase 
	1-This class will handle the creation and functionality of the TagListener.
	2-The class has two variables TWeakObjectPtr. Target which will be the actor that will listen to, and the owner who has the current node. The class also has an event which will be called every time the tag container of the Target changes
	3-It contains a static function that returns a pointer to UWLAsyncTagListener, which in blueprints appear as a node. 
	4-On activate we get hold of the current state of the tags of the target and start a thread safe  ticker class that will repeat the function every frame
	5-The function to repeat everyframe will be AsyncDetectTagChange_Internal. This function works until the target or the owner are no longer valid. We do the comparison asynchronous in any thread in the background with normal priority in order to not block the main thread, once we detect a change we change to the main thread to broadcast and let the owner handle its own behavior


Thank you for the consideration, I hope to hear from you really soon! 

Best regards, Juan Pablo Hernandez Mosti
