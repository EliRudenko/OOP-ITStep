import { Component, Input, Output, EventEmitter } from '@angular/core';

@Component(
{
  selector: 'app-cards-block',
  standalone: true,
  imports: [],
  templateUrl: './cards-block.component.html',
  styleUrl: './cards-block.component.css'
})
export class CardsBlockComponent 
{
  @Input() product: any;
  @Output() viewDetails = new EventEmitter<any>();

  onViewDetails() { this.viewDetails.emit(this.product); }

}