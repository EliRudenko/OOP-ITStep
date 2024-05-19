import { provideRouter, Routes } from "@angular/router";
import { ApplicationConfig } from "@angular/core";

import { Pipe01Component } from './02_pipes/pipe01/pipe01.component';
import { Pipe02Component } from './02_pipes/pipe02/pipe02.component';
import { Pipe03Component } from './02_pipes/pipe03/pipe03.component';
import { Directive01NgClassComponent } from './01_directives/directive01ng-class/directive01ng-class.component';
import { Directive02ngStyleComponent } from './01_directives/directive02ng-style/directive02ng-style.component';
import { Directive03ngIfComponent } from './01_directives/directive03ng-if/directive03ng-if.component';
import { Directive04ngSwitchComponent } from './01_directives/directive04ng-switch/directive04ng-switch.component';
import { Directive05ngForComponent } from './01_directives/directive05ng-for/directive05ng-for.component';
import { Directive06ngTemplateComponent } from './01_directives/directive06ng-template/directive06ng-template.component';
import { Directive07ngContainerComponent } from './01_directives/directive07ng-container/directive07ng-container.component';
import { Directive08ngTemplateOutletComponent } from './01_directives/directive08ng-template-outlet/directive08ng-template-outlet.component';


const appRoutes: Routes = [
  // Directives
  {path: '', component: Directive01NgClassComponent},
  {path: 'ngStyle', component: Directive02ngStyleComponent},
  {path: 'ngIf', component: Directive03ngIfComponent},
  {path: 'ngSwith', component: Directive04ngSwitchComponent},
  {path: 'ngFor', component: Directive05ngForComponent},
  {path: 'templates-directives', component: Directive06ngTemplateComponent},
  {path: 'directive-container', component: Directive07ngContainerComponent},
  {path: 'template-outlet', component: Directive08ngTemplateOutletComponent},
  // Pipes
  {path: 'pipes-str-num', component: Pipe01Component},
  {path: 'pipes-dates', component: Pipe02Component},
  {path: 'pipes-other', component: Pipe03Component},
];
export const appConfig: ApplicationConfig = {
  providers: [provideRouter(appRoutes)]
};
