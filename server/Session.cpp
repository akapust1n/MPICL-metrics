#include "Session.h"
#include "User.h"

#include "Wt/Auth/Dbo/AuthInfo"
#include "Wt/Auth/Dbo/UserDatabase"
#include "Wt/Auth/AuthService"
#include "Wt/Auth/HashFunction"
#include "Wt/Auth/PasswordService"
#include "Wt/Auth/PasswordStrengthValidator"
#include "Wt/Auth/PasswordVerifier"
#include "Wt/Auth/GoogleService"

using namespace Wt;

Session::Session(const std::string& sqliteDb)
  : connection_(sqliteDb)
{
  setConnection(connection_);

  mapClass<User>("user");
  mapClass<AuthInfo>("auth_info");
  mapClass<AuthInfo::AuthIdentityType>("auth_identity");
  mapClass<AuthInfo::AuthTokenType>("auth_token");

  try {
    createTables();
    std::cerr << "Created database." << std::endl;
  } catch (Wt::Dbo::Exception& e) {
    std::cerr << e.what() << std::endl;
    std::cerr << "Using existing database";
  }

  users_ = new UserDatabase(*this);
}



namespace {
  Wt::Auth::AuthService myAuthService;
  Wt::Auth::PasswordService myPasswordService(myAuthService);
  std::vector<const Wt::Auth::OAuthService *> myOAuth;
}

void Session::configureAuth()
{
  myAuthService.setAuthTokensEnabled(true, "logincookie");
  myAuthService.setEmailVerificationEnabled(true);

  Wt::Auth::PasswordVerifier *verifier = new Wt::Auth::PasswordVerifier();
  verifier->addHashFunction(new Wt::Auth::BCryptHashFunction(7));
  myPasswordService.setVerifier(verifier);
  myPasswordService.setAttemptThrottlingEnabled(true);
  myPasswordService.setStrengthValidator(new Wt::Auth::PasswordStrengthValidator());

  if (Wt::Auth::GoogleService::configured())
    myOAuthServices.push_back(new Wt::Auth::GoogleService(myAuthService));
}

const Wt::Auth::AuthService& Session::auth()
{
  return myBaseAuth;
}

const Wt::Auth::PasswordService& Session::passwordAuth()
{
  return myPasswords;
}

const std::vector<const Wt::Auth::OAuthService *>& Session::oAuth()
{
  return myOAuth;
}
