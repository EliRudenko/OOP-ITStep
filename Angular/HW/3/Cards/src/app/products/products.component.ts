import {Component, OnInit} from '@angular/core';

class Product {
  constructor
  (
    public img: string,
    public name: string,
    public list_text: string[]
  ) {}
}

@Component
({
  selector: 'app-product',
  standalone: true,
  imports: [],
  templateUrl: './products.component.html',
  styleUrl: './products.component.css'
})
export class ProductComponent implements OnInit 
{
  products: Product[];

  constructor() { this.products = []; }

  ngOnInit(): void 
  {
    const productData = [
      {
        img: '',
        name: 'Ноутбуки',
        list_text: []
      },

      {
        img: '',
        name: 'Компьютеры',
        list_text: []
      },

      {
        img: '',
        name: 'Мониторы',
        list_text: []
      },

      {
        img: '',
        name: 'Gaming',
        list_text: []
      },

      {
        img: '',
        name: 'Планшеты',
        list_text: []
      },

      {
        img: '',
        name: 'Кабели и переходники',
        list_text: []
      },

      {
        img: '',
        name: 'Кмп. комплектующие',
        list_text: ['SSD', 'Системы охлаждения', 'Видеокарты', 'Оперативная память', 'Процессоры', 'Материнские платы', 'Жесткие диски и дисковые массивы', 'Блоки питания']
      },

      {
        img: '',
        name: 'Сетевое оборудование',
        list_text: ['Маршрутизаторы', 'Коммутаторы', 'Сетевые адаптеры', 'Пассивное сетевое оборудование', 'Беспроводные точки доступа', 'Ретрансляторы Wi-Fi', 'Патч-корды']
      },

      {
        img: '',
        name: 'Наушники и аксессуары',
        list_text: ['Наушники', 'TWS', 'Игровые гарнитуры', 'Вакуумные наушники', 'Наушники вкладыши', 'Накладные наушники', 'Полноразмерные наушники', 'Усилители для наушников', 'Аксессуары для наушников']
      },

      {
        img: '',
        name: 'Клавиатуры и мыши',
        list_text: ['Компьютерные мыши', 'Игровые поверхности', 'Клавиатуры', 'Комплект: клавиатура и мышь', 'Аксессуары для клавиатур и мышей', 'Мышек']
      },

      {
        img: '',
        name: 'Аксессуары',
        list_text: ['Флеш память USB', 'Хабы и кардридеры', 'Аксессуары для ПК и ноутбуков', 'Комплектующие для ноутбуков', 'Сетевые фильтры, адаптеры и удлинители', 'Чехлы для планшетов', 'Сумки, рюкзаки и чехлы для ноутбуков', 'Чистящие средства']
      },

      {
        img: '',
        name: 'Оргтехника',
        list_text: ['МФУ/Принтеры', 'Сканеры', 'Расходные материалы для принтера', 'Доски, флипчарты']
      }
    ];

    for (const data of productData) 
    {
      this.products.push(new Product(data.img, data.name, data.list_text));
    }

  }
}