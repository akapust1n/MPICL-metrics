//#include <Wt/Http/Response>
//#include <Wt/WResource>
//#include <Wt/WServer>
//#include "Router.h"

//#include <zdb/zdb.h>

//using namespace Wt;
//ConnectionPool_T pool;
//int main(int argc, char *argv[])
//{
//    try {
//           WServer server(argv[0]);
//           server.setServerConfiguration(argc, argv); //создаем сервер

//           URL_T url = URL_new("mysql://localhost/mpicl?user=root&password=1111");

//           pool = ConnectionPool_new(url);
//           ConnectionPool_start(pool);

//           Router router; //роутер
//           router.route(server);


//           if (server.start()) {
//               WServer::waitForShutdown();
//               server.stop();
//           }
//       } catch (WServer::Exception& e) {
//           std::cerr << e.what() << std::endl;
//           std::cout<<"why2";
//       } catch (std::exception& e) {
//           std::cerr << "exception: " << e.what() << std::endl;
//       }
//       catch(...)
//       {
//           std::cout<<"why";
//       }

//    return 0;
//}

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WServer>
#include <Wt/WBootstrapTheme>

#include <Wt/Auth/AuthModel>
#include <Wt/Auth/AuthWidget>
#include <Wt/Auth/PasswordService>

#include "Session.h"
#include <iostream>

class AuthApplication : public Wt::WApplication
{
public:
  AuthApplication(const Wt::WEnvironment& env)
    : Wt::WApplication(env),
      session_(appRoot() + "mpicl")
  {
      std::cout<<"\nbefore widget"<<std::endl;

    session_.login().changed().connect(this, &AuthApplication::authEvent);
    std::cout<<"\nbefore widget1"<<std::endl;

    root()->addStyleClass("container");
    setTheme(new Wt::WBootstrapTheme(this));

    useStyleSheet("css/style.css");
   std::cout<<"\nbefore widget2"<<std::endl;
    Wt::Auth::AuthWidget *authWidget
      = new Wt::Auth::AuthWidget(Session::auth(), session_.users(),
                 session_.login());

    authWidget->model()->addPasswordAuth(&Session::passwordAuth());
    authWidget->model()->addOAuth(Session::oAuth());
    authWidget->setRegistrationEnabled(true);

    authWidget->processEnvironment();

    root()->addWidget(authWidget);
  }

  void authEvent() {
    if (session_.login().loggedIn()) {
      const Wt::Auth::User& u = session_.login().user();
      Wt::log("notice")
    << "User " << u.id()
    << " (" << u.identity(Wt::Auth::Identity::LoginName) << ")"
    << " logged in.";
    } else
      Wt::log("notice") << "User logged out.";
  }

private:
  Session session_;
};

Wt::WApplication *createApplication(const Wt::WEnvironment& env)
{
  return new AuthApplication(env);
}

int main(int argc, char **argv)
{
  try {
    Wt::WServer server(argc, argv, WTHTTP_CONFIGURATION);

    server.addEntryPoint(Wt::Application, createApplication);

    Session::configureAuth();

    server.run();
  } catch (Wt::WServer::Exception& e) {
    std::cerr << "ERROR" <<e.what() << std::endl;
  } catch (std::exception &e) {
    std::cerr << "exception: " << e.what() << std::endl;
  }
}
