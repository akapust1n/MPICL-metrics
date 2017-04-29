#ifndef USER_H
#define USER_H
#include <Wt/Dbo/Dbo>
#include <Wt/WGlobal>

namespace dbo = Wt::Dbo;

class User;
typedef Wt::Auth::Dbo::AuthInfo<User> AuthInfo;

class User {
public:
  template<class Action>
  void persist(Action& a)
  {
  }
};
#endif // USER_H
