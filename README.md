ShowKit HelpDesk

Note: This helpdesk uses Parse to store information about users. Be sure to follow the ShowKit guide to enable user creation to create users in your parse app using parse cloud: http://beta.showkit.com/docs#parse_user_registration


This is a simple implementation of a Help Desk type program where a user requests live support from a support agent and the support agent can talk to and provide remote control of the app. The support agent does not have to login on this app, however for demonstration purposes it is all included inside the one application.

Steps to test:

1. Set up the ShowKit module for Parse (http://beta.showkit.com/docs#parse_user_registration)
2. Put your Parse API Key and ShowKit API keys into the AppDelegate.h file
3. Run the project on two seperate iOS Devices
4. Register and login as a support agent on one device
5. Call the support agent using the get support button.
6. Control the app from your second device!