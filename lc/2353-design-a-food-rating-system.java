class FoodRatings {
    private static class FoodNRating implements Comparable<FoodNRating> {
        String food;
        int rating;
        FoodNRating(String food, int rating) {
            this.food = food;
            this.rating = rating;
        }
        @Override
        public int compareTo(FoodNRating x) {
            if (this.rating == x.rating) {
                return this.food.compareTo(x.food);
            }
            return x.rating - this.rating;
        }
    }
    private HashMap<String, PriorityQueue<FoodNRating>> storage;
    //              Cuisine
    private HashMap<String, FoodNRating> foodRatings;
    //              Food    Node
    private HashMap<String, String> foodCuisine;
    //              Food    Cuisine
    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        storage = new HashMap<>();
        foodRatings = new HashMap<>();
        foodCuisine = new HashMap<>();
        for (int i = 0; i < foods.length; ++i) {
            String f = foods[i], c = cuisines[i];
            int r = ratings[i];
            FoodNRating node = new FoodNRating(f, r);
            if (!storage.containsKey(c)) {
                PriorityQueue<FoodNRating> pq = new PriorityQueue<>();
                pq.add(node);
                storage.put(c, pq);
            } else {
                storage.get(c).add(node);
            }
            foodRatings.put(f, node);
            foodCuisine.put(f, c);
        }
    }
    public void changeRating(String food, int newRating) {
        FoodNRating newNode = new FoodNRating(food, newRating);
        FoodNRating node = foodRatings.get(food);
        foodRatings.put(food, newNode);
        String c = foodCuisine.get(food);
        storage.get(c).remove(node);
        storage.get(c).add(newNode);
    }
    public String highestRated(String cuisine) {
        return storage.get(cuisine).peek().food;
    }
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings obj = new FoodRatings(foods, cuisines, ratings);
 * obj.changeRating(food,newRating);
 * String param_2 = obj.highestRated(cuisine);
 */