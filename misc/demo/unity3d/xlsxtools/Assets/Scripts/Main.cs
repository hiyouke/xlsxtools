using UnityEngine;
using System.Collections.Generic;

public class Main : MonoBehaviour {

	// Use this for initialization
	void Start () {
		Dictionary<int, ItemItemConfig> configs = ConfigMgr.GetInstance().ItemItem.configs;
		foreach(KeyValuePair<int,ItemItemConfig> kvp in configs)
		{
			Debug.Log("key : " + kvp.Key + " value : " + kvp.Value.name);
		}
	}
}
