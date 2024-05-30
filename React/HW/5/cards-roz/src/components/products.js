import React from 'react';
import './products.css';

function SectionElement({ src, alt, linkText, href, additionalLinks }) {
    return (
        <div className='section__element'>
            <img src={src} alt={alt}></img>
            <a href={href}>
                <span className='section__text-header'>{linkText}</span>
            </a>
            {additionalLinks && (
                <div className='section__element-links'>
                    {additionalLinks.map((link, index) => (
                        <a key={index} href={link.href}><span>{link.text}</span></a>
                    ))}
                </div>
            )}
        </div>
    );
}

export class Section extends React.Component {
    render() {
        return (
            <div className='section'>
                <div className='section__elements'>
                    <SectionElement
                        src="https://video.rozetka.com.ua/img_superportal/kompyutery_i_noutbuki/noutbuki.png"
                        alt="Ноутбуки"
                        linkText="Ноутбуки"
                        href="#"
                    />
                    <SectionElement
                        src="https://video.rozetka.com.ua/img_superportal/kompyutery_i_noutbuki/kompyutery.png"
                        alt="Компьютеры, неттопы, моноблоки"
                        linkText="Компьютеры, неттопы, моноблоки"
                        href="#"
                    />
                    <SectionElement
                        src="https://video.rozetka.com.ua/img_superportal/kompyutery_i_noutbuki/monitory.png"
                        alt="Мониторы"
                        linkText="Мониторы"
                        href="#"
                    />
                    <SectionElement
                        src="https://video.rozetka.com.ua/img_superportal/kompyutery_i_noutbuki/tovary-dlya-gejmerov.png"
                        alt="Gaming"
                        linkText="Gaming"
                        href="#"
                    />
                    <SectionElement
                        src="https://video.rozetka.com.ua/img_superportal/kompyutery_i_noutbuki/planshety.png"
                        alt="Планшеты"
                        linkText="Планшеты"
                        href="#"
                    />
                    <SectionElement
                        src="https://video.rozetka.com.ua/img_superportal/kompyutery_i_noutbuki/kabeli-i-perekhodniki.png"
                        alt="Кабели и переходники"
                        linkText="Кабели и переходники"
                        href="#"
                    />
                    <SectionElement
                        src="https://video.rozetka.com.ua/img_superportal/kompyutery_i_noutbuki/kompyuternye-komplektuyushchie.png"
                        alt="Компьютерные комплектующие"
                        linkText="Компьютерные комплектующие"
                        href="#"
                        additionalLinks={[
                            { href: '#', text: 'SSD' },
                            { href: '#', text: 'Системы охлаждения' },
                            { href: '#', text: 'Видеокарты' },
                            { href: '#', text: 'Оперативная память' },
                            { href: '#', text: 'Процессоры' },
                            { href: '#', text: 'Материнские платы' },
                            { href: '#', text: 'Жесткие диски' },
                            { href: '#', text: 'Блоки питания' }
                        ]}
                    />
                    <SectionElement
                        src="https://video.rozetka.com.ua/img_superportal/kompyutery_i_noutbuki/setevoe-oborudovanie.png"
                        alt="Сетевое оборудование"
                        linkText="Сетевое оборудование"
                        href="#"
                        additionalLinks={[
                            { href: '#', text: 'Маршрутизаторы' },
                            { href: '#', text: 'Коммутаторы' },
                            { href: '#', text: 'Сетевые адаптеры' },
                            { href: '#', text: 'Пассивное сетевое оборудование' },
                            { href: '#', text: 'Точки доступа Wi-Fi' },
                            { href: '#', text: 'Ретрансляторы Wi-Fi сигнала' },
                            { href: '#', text: 'Патч-корды' }
                        ]}
                    />
                    <SectionElement
                        src="https://video.rozetka.com.ua/img_superportal/kompyutery_i_noutbuki/naushniki-i-aksessuary.png"
                        alt="Наушники и аксессуары"
                        linkText="Наушники и аксессуары"
                        href="#"
                        additionalLinks={[
                            { href: '#', text: 'Наушники' },
                            { href: '#', text: 'TWS' },
                            { href: '#', text: 'Игровые гарнитуры' },
                            { href: '#', text: 'Вакуумные наушники' },
                            { href: '#', text: 'Наушники вкладыши' },
                            { href: '#', text: 'Накладные наушники' },
                            { href: '#', text: 'Полноразмерные наушники' },
                            { href: '#', text: 'Усилители для наушников' },
                            { href: '#', text: 'Аксессуары для наушников' }
                        ]}
                    />
                    <SectionElement
                        src="https://video.rozetka.com.ua/img_superportal/kompyutery_i_noutbuki/klaviatury-i-myshi.png"
                        alt="Клавиатуры и мыши"
                        linkText="Клавиатуры и мыши"
                        href="#"
                        additionalLinks={[
                            { href: '#', text: 'Компьютерные мыши' },
                            { href: '#', text: 'Коврики для мыши' },
                            { href: '#', text: 'Клавиатуры' },
                            { href: '#', text: 'Комплекты клавиатуры и мыши' },
                            { href: '#', text: 'Аксессуары для клавиатур и мышей' }
                        ]}
                    />
                    <SectionElement
                        src="https://video.rozetka.com.ua/img_superportal/kompyutery_i_noutbuki/aksessuari-dlia-elektronyky.png"
                        alt="Аксессуары для электроники"
                        linkText="Аксессуары для электроники"
                        href="#"
                        additionalLinks={[
                            { href: '#', text: 'USB флешки' },
                            { href: '#', text: 'Хабы и кардридеры' },
                            { href: '#', text: 'Аксессуары для ПК и ноутбуков' },
                            { href: '#', text: 'Комплектующие для ноутбуков' },
                            { href: '#', text: 'Сетевые фильтры' },
                            { href: '#', text: 'Чехлы и клавиатуры для планшетов' },
                            { href: '#', text: 'Сумки, рюкзаки и чехлы для ноутбуков' },
                            { href: '#', text: 'Чистящие средства' }
                        ]}
                    />
                    <SectionElement
                        src="https://video.rozetka.com.ua/img_superportal/kompyutery_i_noutbuki/ofisnaya-tekhnika.png"
                        alt="Офисная техника"
                        linkText="Офисная техника"
                        href="#"
                        additionalLinks={[
                            { href: '#', text: 'Принтеры и МФУ' },
                            { href: '#', text: 'Сканеры' },
                            { href: '#', text: 'Расходные материалы для принтеров' },
                            { href: '#', text: 'Доски, флипчарты' }
                        ]}
                    />
                </div>
            </div>
        );
    }
}