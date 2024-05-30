import React from "react";
import './styles.css';

export function Card(props) {
    const features = {
        Basic: [
            {text: "Доступ к основным функциям Spotify", included: true},
            {text: "Ограниченные пропуски треков", included: true},
            {text: "Без рекламы", included: false},
            {text: "Ограниченная настройка плейлистов", included: false},
            {text: "Регулярные обновления", included: true}
        ],
        Standard: [
            {text: "Доступ ко всем функциям Spotify", included: true},
            {text: "Неограниченные пропуски треков", included: true},
            {text: "Без рекламы", included: false},
            {text: "Средняя настройка плейлистов", included: true},
            {text: "Приоритетные обновления", included: false}
        ],
        Premium: [
            {text: "Все функции Spotify", included: true},
            {text: "24/7 поддержка", included: true},
            {text: "Без рекламы", included: true},
            {text: "Полная настройка плейлистов", included: true},
            {text: "Мгновенные обновления", included: true}
        ]
    };

    const headerStyle = {
        backgroundColor: props.color
    };

    return (
        <main className="pricing-card">
            <div className="card-content">
                <div className="card-header" style={headerStyle}>{props.tarif}</div>
                <div className="price-box">
                    <div className="price">{props.price} грн</div>
                    <div className="per-month">в месяц</div>
                </div>
                <div className="features-list">
                    {features[props.tarif].map((feature, index) => (
                        <div key={index} className={`feature ${feature.included ? 'check' : 'cross'}`}>
                            {feature.text}
                        </div>
                    ))}
                </div>
                <div className="subscribe-button">Выбрать</div>
            </div>
        </main>
    );
}
