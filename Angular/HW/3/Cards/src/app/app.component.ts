import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { ProductComponent } from './products/products.component';

@Component({
  selector: 'app-root',
  standalone: true,
  imports: [RouterOutlet, ProductComponent],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'Cards';
}
