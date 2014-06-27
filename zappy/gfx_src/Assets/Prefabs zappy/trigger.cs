using UnityEngine;
using System.Collections;

public class trigger : MonoBehaviour {

	public int orientation;
	public int level;
	public float x_pos;
	public float y_pos;
	public string team;
	public int Health;
	public int linemate;
	public int deraumere;
	public int sibur;
	public int mendiane;
	public int phiras;
	public int thystame;
	public bool Mouse_ok;
	public int	nb;
	// Use this for initialization
	void Start () {
		Mouse_ok = false;
	}

	// Update is called once per frame
	void Update () {

	}

	void OnGUI()
	{
		if (Mouse_ok)
		{
			GUI.Box(new Rect(Input.mousePosition.x, Input.mousePosition.y, 200, 100), this.Health + " " + this.team + " Nb :" + this.nb + "\n"
				+ "Level : " + this.level + "\n" + "deraumere: "
				+ this.deraumere + " thystame :" + this.thystame +"\n"+ " linemate : " + this.linemate +
				 " sibur : " + this.sibur
				+ "\n mendiane : " + this.mendiane + " phiras : " + this.phiras);
		}
	}
	void OnMouseEnter()
	{
		Mouse_ok = true;
	}

	void OnMouseExit()
	{
		Mouse_ok = false;
		//efface la tooltip
	}
}
