UEFirestore is **NOT** affiliated, associated, authorized, endorsed by, or in any way officially connected with Google, or any of its subsidiaries.

All product and company names are trademarks or registered trademarks of their respective holders. Use of them does not imply any affiliation with or endorsement by them.

# UEFirestore
**Unofficial** plugin for interaction between Google Cloud Firestore and Unreal Engine

**Warning** this plugin is only designed for usage via a GCloud service account. This means it will only work server side because it needs a reference to a service account key file. THIS PLUGIN IS CAPABLE OF DELETING FIRESTORE DATA, Loss of data is not the responsiblity of the author of UEFirestore. Be careful.

### About
This plugin works by communicating to the firestore api via rest. it currently does not support the firestore built in json system so this plugin may only write one string (probably a Json string) to each document viewable on the cloud console. This is effectively as powerful, but will not display pretty on the cloud console.
### Blueprint Usage
- Get your project ID from the cloud console and store it in a string variable.
- Create a service account in IAM & Admin -> Service Accounts. will require atleast a permission of "Cloud Datastore Owner"
- Open service account's page and "ADD KEY", Create new key as json, store key file securely.
- Make a "Get GCloud Access Token Node"
- Drag the event pin off and create a new event
- Set a variable to store the access token, this token expires 1 hour
after recieving it.
![ex1](https://i.imgur.com/Wwt11vM.png)

#### Set a document's content with the "Update Firestore Document" node.
- Connect OAUTHToken with your stored access token
- Connect Project ID to your stored project ID.
- In "Document Path" input the path in your firestore to the document you want to write to, you could generate this programatically.
- input the string you want to write to firestore into "Content"
- **hint:** you can use the included FSJson objects to build a json string from a struct / other data source.
- Create an event off of the event pin.
- the returned string gives the full json response from the api, useful for debugging.
![ex2](https://i.imgur.com/tZb9gpU.png)

#### Read a document's contents with the "Request Firestore Document" node.
- Connect OAUTHToken with your stored access token
- Connect Project ID to your stored project ID.
- In "Document Path" input the path in your firestore to the document you want to read from, you could generate this programatically.
- Create an event off of the event pin.
- the returned string has the string content of your document you set via "Update Firestore Document" node.
 ![ex3](https://i.imgur.com/CfqDSN9.png)

### Using the FSJsonObject
The FSJsonObject can be used to help store data into the document string.
- Make a "Construct Object From Class" node
- set the class to FSJsonObject
- set a variable to contain it
- set fields as you desire
- use the "Get Json String" function of your object to put the string into a update.
![ex4](https://i.imgur.com/442OrFJ.png)