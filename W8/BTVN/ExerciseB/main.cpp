#include <format>
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::string;
using std::vector;

class Post {
protected:
  string _author;
  string _title;
  string _content;

public:
  Post();
  Post(std::string author, std::string title, std::string content)
      : _author(author), _title(title), _content(content) {}
  virtual string toString();
};

class Comment {
protected:
  std::string _commentAuthor;
  std::string _commentcontent;

public:
  Comment();
  Comment(std::string commentAuthor, std::string commentContent)
      : _commentAuthor(commentAuthor), _commentcontent(commentContent) {}
  string commentAuthor();
  string commentContent();
};

class GraphPost : public Post {
private:
  int _likes;
  vector<Comment *> _comments;

public:
  GraphPost(Post post, int likes, vector<Comment *> comments)
      : Post(post), _likes(likes), _comments(comments) {}
  string toString() override;
};

int main() {
  auto author = "Jane";
  auto title = "3 tips to learn English effectively";
  string content =
      "To learn English effectively, you can try these 3 tips.\n1. Practice on "
      "a daily basis.\n2.Take time to understand difficult paragraphs\n3.Try "
      "new things everyday ";
  Post p(author, title, content);
  // std::cout << p.toString();
  vector<Comment *> comments = {new Comment("Anna", "Great work."),
                                new Comment("Blash", "This helps me a lot!"),
                                new Comment("Jack", " Thanks for your post.")};
  GraphPost gp(p, 5, comments);
  cout << gp.toString();
  return 0;
}

Post::Post() {
  // Do nothing
}

std::string Post::toString() {
  return std::format("Author: {}\nTitle: {}\nContent:\n{}", _author, _title,
                     _content);
}

Comment::Comment() {
  // Do nothing
}

string Comment::commentAuthor() { return _commentAuthor; }
string Comment::commentContent() { return _commentcontent; }
string GraphPost::toString() {
  std::string result =
      std::format("{}\nLikes: {}\nComments: {}\n", Post::toString(), _likes,
                  this->_comments.size());
  for (const auto &comment : this->_comments) {
    result += std::format("- {}: {}\n", comment->commentAuthor(),
                          comment->commentContent());
  }
  return result;
}
