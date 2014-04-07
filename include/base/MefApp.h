#ifndef MEFAPP_H
#define MEFAPP_H

#include "MooseApp.h"

class MefApp;

template<>
InputParameters validParams<MefApp>();

class MefApp : public MooseApp
{
public:
  MefApp(const std::string & name, InputParameters parameters);
  virtual ~MefApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* MEFAPP_H */
