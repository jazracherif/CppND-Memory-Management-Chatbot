#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

/* The chatBot implements logic of determining what should be the answer to a user query
- It is anchored on one of the nodes of the graph nodes, starting at root node at startup
- It computes next edge on the knowledge graph based on levenstein distance between user input and keywords associated with an edge
- It moves along graph once it computes the next answer.
- The only ressource it manages is the image associated with
*/
class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();     // destructor

    //// STUDENT CODE
    ////
    ChatBot(const ChatBot &other);  // regular constructor
    ChatBot(ChatBot &&other);  // move constructor
    ChatBot& operator=(const ChatBot &other); // copy assignment
    ChatBot& operator=(ChatBot &&other); // move assignment

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    ChatLogic* GetChatLogicHandle() { return _chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
