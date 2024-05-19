import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import {CardsContainerComponent} from "./cards-container/cards-container.component";
import {CardsBlockComponent} from "./cards-block/cards-block.component";

@Component(
{
  selector: 'app-root',
  standalone: true,
  imports: 
  [
    RouterOutlet,
    CardsContainerComponent,
    CardsBlockComponent
  ],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent 
{
  title = 'projcards';

  selectedProduct: any;
  discountApplied = false;

  onProductSelected(product: any) { this.selectedProduct = product; }

  applyDiscount() { this.discountApplied = true; }

  discountedPrice(price: number): number 
  {
    if (this.discountApplied) { return price * (1 - 0.15); }
    return price;
  }
}