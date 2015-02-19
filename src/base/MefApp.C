#include "MefApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<MefApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

MefApp::MefApp(const std::string & name, InputParameters parameters) :
    MooseApp(name, parameters)
{
  srand(libMesh::processor_id());
  
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  MefApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  MefApp::associateSyntax(_syntax, _action_factory);
}

MefApp::~MefApp()
{
}

extern "C" void MefApp__registerApps() { MefApp::registerApps(); }
void
MefApp::registerApps()
{
  registerApp(MefApp);
}

void
MefApp::registerObjects(Factory & factory)
{
}

void
MefApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
