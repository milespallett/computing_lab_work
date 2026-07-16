from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def home():
    recipes = [
        {'id': 1, 'title': 'Spaghetti Carbonara', 'description': 'A classic Itlian pasta dish.'},
        {'id': 2, 'title': 'Chicken Curry', 'description': 'A spicy and flavourful dish.'},
        {'id': 3, 'title': 'Chocolate Cake', 'description': 'A rich and moist dessert.'}
    ]
    return render_template('index.html', recipes=recipes)

@app.route('/recipe/<int:recipe_id>')
def recipe_detail(recipe_id):
    recipes = {
        1: {'title': 'Spaghetti Carbonara', 'ingredients': ['Pasta', 'Eggs', 'Cheese', 'Bacon']},
        2: {'title': 'Chicken Curry', 'ingredients': ['Chicken', 'Curry Powder', 'Coconut Milk', 'Onions']},
        3: {'title': 'Chocolate Cake', 'ingredients': ['Flour', 'Sugar', 'Cocoa', 'Eggs']}
    }
    recipe = recipes.get(recipe_id)
    if recipe is None:
        return render_template('no_recipes.html')
    return render_template('recipe.html', recipe=recipe)

if __name__ == "__main__":
    app.run(debug=True, host='0.0.0.0', port=8000)