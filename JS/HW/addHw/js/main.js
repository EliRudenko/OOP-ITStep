const wildebeest = new Wildebeest(100, true);
const bison = new Bison(150, true);

const lion = new Lion(120);
const wolf = new Wolf(90);

const africa = new Africa();
const northAmerica = new NorthAmerica();

const animalWorld = new AnimalWorld();

animalWorld.mealsHerbivores([wildebeest, bison]);
animalWorld.nutritionCarnivores([lion, wolf], wildebeest);