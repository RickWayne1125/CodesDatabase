import com.sun.jdi.event.StepEvent;

import java.util.*;

class Solution {
    public static Map<String,Integer> frequencyOfListElements(List<String> items ) {
        if (items == null || items.size() == 0) return null;
        Map<String, Integer> map = new HashMap<String, Integer>();
        for (String temp : items) {
            Integer count = map.get(temp);
            map.put(temp, (count == null) ? 1 : count + 1);
        }
        return map;
    }
    public List<List<String>> displayTable(List<List<String>> orders) {
        List<List<String>> ans = new ArrayList<>();
        List<String> table = new ArrayList<>();
        List<String> food = new ArrayList<>();
        Map<String, List<String>> tables = new HashMap<>();
        Map<String, Integer> foods = new HashMap<>();
        for(int i=0; i<orders.size(); i++){
            List<String> temp = new ArrayList<>();
            if(tables.containsKey(orders.get(i).get(1))){
                temp = tables.get(orders.get(i).get(1));
            }
            else{
                table.add(orders.get(i).get(1));
            }
            temp.add(orders.get(i).get(2));
            tables.put(orders.get(i).get(1), temp);
            if(!foods.containsKey(orders.get(i).get(2))){
                foods.put(orders.get(i).get(2), 1);
                food.add(orders.get(i).get(2));
            }
        }
        Collections.sort(table,new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                int y = Integer.parseInt(o2);
                int x = Integer.parseInt(o1);
                return x-y;
            }
        });
        Collections.sort(food);
        List<String> title = new ArrayList<>();
        title.add("Table");
        for(int i=0; i<food.size(); i++){
            title.add(food.get(i));
        }
        ans.add(title);
        for(int i=0; i<table.size(); i++){
            List<String> temp = new ArrayList<>();
            temp.add(table.get(i));
            Map<String, Integer> cnt = frequencyOfListElements(tables.get(table.get(i)));
            for(int j=0; j<food.size(); j++){
                if(cnt.containsKey(food.get(j))){
                    temp.add(""+cnt.get(food.get(j)));
                }
                else temp.add("0");
            }
            ans.add(temp);
        }
        return ans;
    }
}