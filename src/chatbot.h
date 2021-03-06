#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <memory>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    std::shared_ptr<wxBitmap> _image; // avatar image

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
    ~ChatBot();

    //// STUDENT CODE
    ////
    ChatBot(ChatBot &source);  
    ChatBot &operator=(ChatBot &source);  

    ChatBot(ChatBot &&source); // You can move the ChatBot

    ChatBot &operator=(ChatBot &&source); //This is a move assignment.  Also okay.

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode* node);
    void SetRootNode(GraphNode* rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic* chatLogic) { _chatLogic = chatLogic; }
    std::shared_ptr<wxBitmap> GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */