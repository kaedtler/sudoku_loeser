Imports System.ComponentModel
Imports System.Configuration.Install

Public Class Installer1

    Public Sub New()
        MyBase.New()

        'Dieser Aufruf ist für den Komponenten-Designer erforderlich.
        InitializeComponent()

        'Initialisierungscode nach dem Aufruf von InitializeComponent hinzufügen

    End Sub
    <Security.Permissions.SecurityPermission(Security.Permissions.SecurityAction.Demand)> _
Public Overrides Sub Commit(ByVal savedState As  _
  System.Collections.IDictionary)

        MyBase.Commit(savedState)
        System.Diagnostics.Process.Start("http://ok-city.de")
    End Sub

End Class
