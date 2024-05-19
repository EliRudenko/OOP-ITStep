import {Injectable} from '@angular/core';

export class Product 
{
  public id: number;
  public name: string;
  public price: number;
  public image: string;
  public description: string;

  constructor(id: number, name: string, price: number, image: string, description: string) 
  {
    this.id = id;
    this.name = name;
    this.price = price;
    this.image = image;
    this.description = description;
  }
}

@Injectable({ providedIn: 'root' })
export class ProductsServiceService 
{
  constructor() {}

  private products: Product[] = [
    {
      id: 1,
      name: 'Ноутбук ASUS TUF Gaming A15',
      price: 43999,
      image: '',
      description: '2023) FA507NU-LP131 (90NR0EB8-M00EK0) Jaeger Gray / 15.6" IPS Full HD 144 Гц / AMD Ryzen 5 7535HS / RAM 16 ГБ / SSD 1 ТБ / nVidia GeForce RTX 4050'
    },
    {
      id: 2,
      name: 'Ноутбук Acer Aspire 7',
      price: 29999,
      image: '',
      description: 'A715-76G-56U7 (NH.QN4EU.001) Charcoal Black / Intel Core i5-12450H / RAM 16 ГБ / SSD 512 ГБ / nVidia GeForce RTX 2050, 4 ГБ / Підсвітка клавіатури'
    },
    {
      id: 3,
      name: 'Ноутбук Lenovo IdeaPad Slim 5 ',
      price: 25999,
      image: '',
      description: '16IAH8 (83BG001ARA) Cloud Grey / 16" IPS WUXGA / Intel Core i5-12450H / RAM 16 ГБ / SSD 512 ГБ / Підсвічування клавіатури / Зарядка через Type-C'
    },
    {
      id: 4,
      name: 'Ноутбук Apple MacBook Air 13',
      price: 36499,
      image: '',
      description: 'M1 8/256GB 2020 (MGN63) Space Gray'
    },
    {
      id: 5,
      name: 'Ноутбук HP Laptop 15s-fq5000ua',
      price: 17999,
      image: '',
      description: '(7X8E4EA) Spruce Blue / Intel Core i3-1215U / RAM 16 ГБ / SSD 512 ГБ'
    },
    {
      id: 6,
      name: 'Ноутбук Lenovo IdeaPad 3',
      price: 22999,
      image: '',
      description: '15IAU7 (82RK011NRA) Arctic Grey / 15.6" IPS Full HD / Intel Core i5-1235U / RAM 16 ГБ / SSD 512 ГБ / Підсвітка клавіатури'
    },
    {
      id: 7,
      name: 'Ноутбук Acer Aspire 7 ',
      price: 32999,
      image: '',
      description: 'A715-76G-560W (NH.QMMEU.002) Charcoal Black / Intel Core i5-12450H / RAM 16 ГБ / SSD 512 ГБ / nVidia GeForce RTX 3050, 4 ГБ / Підсвітка клавіатури'
    },
    {
      id: 8,
      name: 'Ноутбук ASUS TUF Gaming A15',
      price: 35999,
      image: '',
      description: 'FA506NC-HN026 (90NR0JF7-M004N0) Graphite Black'
    },

  ];

  getAllProducts() 
  {
    console.log("get all products")
    return this.products;
  }

  filterProducts(filter: string): Product[] 
  {
    console.log("filter products")
    return this.products.filter(product => product.name.toLowerCase().includes(filter.toLowerCase()));
  }
  sortByNameAsc(): Product[] 
  {
    console.log("sort by nameAsc")
    return [...this.products].sort((a, b) => a.name.localeCompare(b.name));
  }
  sortByNameDesc(): Product[] 
  {
    console.log("sort by nameDesc")
    return [...this.products].sort((a, b) => b.name.localeCompare(a.name));
  }
  sortByMaxPrice(): Product[] 
  {
    console.log("sort by max price")
    return [...this.products].sort((a, b) => b.price - a.price);
  }
  sortByMinPrice(): Product[] 
  {
    console.log("sort by min price")
    return [...this.products].sort((a, b) => a.price - b.price);
  }
}