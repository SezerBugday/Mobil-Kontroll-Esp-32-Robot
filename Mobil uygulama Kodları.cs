using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Firebase;
using Firebase.Database;
using UnityEngine.UI;
public class Buttons : MonoBehaviour
{

    /*
        mobil uygulama Unity 3D ile oluþturulmuþ olup butonlardaki kodlar aþaðýdaki gibidir.
    */

    public void Left()
    {
        FirebaseDatabase.DefaultInstance.RootReference.Child("position").SetValueAsync(1);
    }
    public void Right()
    {
        FirebaseDatabase.DefaultInstance.RootReference.Child("position").SetValueAsync(2);
    }
    public void Forward()
    {
        FirebaseDatabase.DefaultInstance.RootReference.Child("position").SetValueAsync(3);
    }
    public void Backward()
    {
        FirebaseDatabase.DefaultInstance.RootReference.Child("position").SetValueAsync(4);
    }
    public void Stop()
    {
        FirebaseDatabase.DefaultInstance.RootReference.Child("position").SetValueAsync(5);

    }

}
