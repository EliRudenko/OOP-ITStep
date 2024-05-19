import {Component} from '@angular/core';
import {RouterOutlet} from '@angular/router';
import {ProductsServiceService} from "./products-service.service";
import {CardsContainerComponent} from "./cards-container/cards-container.component";

@Component({
  selector: 'app-root',
  standalone: true,
  imports: [RouterOutlet,CardsContainerComponent],
  providers: [ProductsServiceService],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'Products';
}
