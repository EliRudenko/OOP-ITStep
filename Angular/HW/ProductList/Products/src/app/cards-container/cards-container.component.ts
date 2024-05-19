import {Component, OnInit} from '@angular/core';
import {ProductsServiceService, Product} from "../products-service.service";
import {NgFor, NgIf} from "@angular/common";
import {FormsModule} from "@angular/forms";
import {NgModel} from "@angular/forms";

@Component({
  selector: 'app-cards-container',
  standalone: true,
  imports: [NgFor, NgIf, FormsModule],
  providers: [ProductsServiceService, NgModel],
  templateUrl: './cards-container.component.html',
  styleUrl: './cards-container.component.css'
})
export class CardsContainerComponent implements OnInit {
  products: Product[] = [];
  filteredProducts: Product[] = [];
  filter: string = '';
  sortOption: string = '';

  constructor(private productService: ProductsServiceService) {
  }

  ngOnInit() {
    this.products = this.productService.getAllProducts();
    this.filteredProducts = this.products;
  }

  filterProducts() {
    this.filteredProducts = this.productService.filterProducts(this.filter);
  }

  applySort() {
    switch (this.sortOption) {
      case 'nameAsc':
        this.filteredProducts = this.productService.sortByNameAsc();
        break;
      case 'nameDesc':
        this.filteredProducts = this.productService.sortByNameDesc();
        break;
      case 'maxPrice':
        this.filteredProducts = this.productService.sortByMaxPrice();
        break;
      case 'minPrice':
        this.filteredProducts = this.productService.sortByMinPrice();
        break;
      default:
        this.filteredProducts = this.products;
    }
  }

}