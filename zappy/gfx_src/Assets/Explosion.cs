using UnityEngine;
using System.Collections;

public class Explosion : MonoBehaviour {

	public GameObject jewel;
	public Transform origin;
	public float posx;
	public float posy;
	private int save;
	public float altitude;
	// Use this for initialization
	void Start () {
		save = 0;
	}

	// Update is called once per frame
	void Update ()
	{
		if (save % 30 != 29)
			save += 1;
		else if (save < 100)
		{
			save += 1;
			jewel = Instantiate (jewel, new Vector3(posx, altitude, posy), origin.rotation) as GameObject;
			jewel.name = "jewel" + save;
			Destroy(jewel, 30.0f);
		}
		else
			save = 0;

	}
}
