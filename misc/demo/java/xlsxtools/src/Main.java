import java.util.Map;

import com.xlsxtools.ConfigMgr;
import com.xlsxtools.ItemItemConfigTable.ItemItemConfig;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
				
		Map<Integer, ItemItemConfig> configs = ConfigMgr.GetInstance().ItemItem.getConfigs();
		for (Integer key : configs.keySet()) {  
			  
			ItemItemConfig config = configs.get(key);  
		  
		    System.out.println("Key = " + key + ", Value = " + config.name);  
		  
		}  
		
	}
}
