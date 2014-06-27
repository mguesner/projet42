using UnityEngine;
using System.Collections;
using System;
using System.IO;
using System.Net;
using System.Text;
using System.Net.Sockets;

public class Rotate_jewel : MonoBehaviour {

	public int speed_rot_up = 5;
	public int speed_rot_right = 5;
	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		transform.Rotate(Vector3.right * (Time.deltaTime * speed_rot_right));
		transform.Rotate(Vector3.up * Time.deltaTime * speed_rot_up, Space.World);
	}
}
