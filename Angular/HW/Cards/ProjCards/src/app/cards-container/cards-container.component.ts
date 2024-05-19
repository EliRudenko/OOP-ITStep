import {Component, OnInit, Input, Output, EventEmitter, output} from '@angular/core';
import {CommonModule} from '@angular/common';
import {CardsBlockComponent} from "../cards-block/cards-block.component";
import {NgFor} from "@angular/common";

class Product {
  constructor(
    public id: number,
    public name: string,
    public price: number,
    public description: string,
    public color: string
  ) {
  }
}

@Component({
  selector: 'app-cards-container',
  standalone: true,
  imports: [CommonModule, CardsBlockComponent, NgFor],
  templateUrl: './cards-container.component.html',
  styleUrl: './cards-container.component.css'
})
export class CardsContainerComponent implements OnInit {

  products: Product[];

  constructor() {
    this.products = [];
  }

  ngOnInit(): void {
    const productData = [
      {id: 1, name: 'First', price: 100, description: 'First description..', color: 'lightblue'},
      {id: 2, name: 'Second', price: 180, description: 'Second description..', color: 'lightblue'},
      {id: 3, name: 'Third', price: 260, description: 'Third description..', color: 'lightblue'},
    ];

    for (const data of productData) {
      this.products.push(new Product(data.id, data.name, data.price, data.description, data.color));
    }
  }

  selectedProduct: any;

  @Output() viewDetails = new EventEmitter<any>();

  viewProductDetails(product: any) {
    this.selectedProduct = product;
    this.viewDetails.emit(this.selectedProduct);
  }
}